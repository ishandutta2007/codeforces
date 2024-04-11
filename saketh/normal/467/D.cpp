#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

int N, M;
vector<string> essay;
unordered_map<string, vector<string> > syn;

void make_lower(string &arg){
    for(int i=0; i<arg.length(); i++)
        if(arg[i] <= 'Z')
            arg[i] += 'a' - 'A';
}

int r_count(string &arg){
    int ans = 0;
    for(int i=0; i<arg.length(); i++)
        ans += arg[i] == 'r';
    return ans;
}

pair<int, int> small(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return (a.second < b.second)?a:b;
    return (a.first < b.first)?a:b;
}

unordered_map<string, int> scc, idx, low;
stack<string> tarj;
unordered_set<string> stak;
int k = 0, s = 0;

void find_scc(string &word){
    if(scc.count(word)) return;

    idx[word] = k;
    low[word] = k;
    k++;
    tarj.push(word);
    stak.insert(word);

    for(int i=0; i<syn[word].size(); i++){
        if(scc.count(syn[word][i])) continue;

        if(!idx.count(syn[word][i])){
            find_scc(syn[word][i]);
            low[word] = min(low[word], low[syn[word][i]]);
        }
        else if(stak.count(syn[word][i]))
            low[word] = min(low[word], idx[syn[word][i]]);
    }

    if(low[word] == idx[word]){
        while(tarj.top() != word){
            scc[tarj.top()] = s;
            stak.erase(tarj.top());
            tarj.pop();
        }
        scc[word] = s++;
        stak.erase(tarj.top());
        tarj.pop();
    }
}

vector<int> adj[300005];
bool seen[300005];
pair<int, int> val[300005], ans[300005];

pair<int, int> best(int i){
    if(seen[i]) return ans[i];
    seen[i] = true;
    ans[i] = val[i];

    for(int j=0; j<adj[i].size(); j++)
        ans[i] = small(ans[i], best(adj[i][j]));
    return ans[i];
}

unordered_set<string> dict;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    string tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        make_lower(tmp);
        essay.push_back(tmp);
        dict.insert(tmp);
    }
    
    cin >> M;
    string tmp2;
    for(int i=0; i<M; i++){
        cin >> tmp >> tmp2;
        make_lower(tmp);
        make_lower(tmp2);
        syn[tmp].push_back(tmp2);
        dict.insert(tmp);
        dict.insert(tmp2);
    }
   
    for(unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); it++){
        string w = *it;
        k = 0;
        find_scc(w);
    }

    for(int i=0; i<s; i++)
        val[i] = make_pair(INT_MAX, INT_MAX);

    for(unordered_set<string>::iterator it = dict.begin(); it!=dict.end(); it++){
        string w = *it;
        val[scc[w]] = small(val[scc[w]], make_pair(r_count(w), w.length()));
    }

    for(unordered_map<string, vector<string> >::iterator it = syn.begin(); it!=syn.end(); it++){
        int a = scc[it->first];
        for(int i=0; i<(it->second).size(); i++){
            int b = scc[(it->second)[i]];
            if(a!=b)  adj[a].push_back(b);
        }
    }

    long long rc = 0, len = 0;
    for(int i=0; i<N; i++){
        pair<int, int> res = best(scc[essay[i]]);
        rc += res.first;
        len += res.second;
    }
    cout << rc << " " << len << endl;
    return 0;
}