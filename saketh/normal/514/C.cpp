#include <iostream>
#include <vector>
using namespace std;

const int MAXL = 600005;
int N, M;

struct node{
    bool end;
    int depth;
    int succ[26];   
} trie[MAXL]; int TAIL=1;

string s;
void ins(){
    int loc = 0; 
    for(int idx = 0; idx < s.length(); idx++){
        int let = s[idx] - 'a';
        
        if(trie[loc].succ[let] == 0)
            trie[loc].succ[let] = TAIL++;

        loc = trie[loc].succ[let];
        trie[loc].depth = idx + 1;
    }

    trie[loc].end = true;
}

bool query_intol(int i, int l){
    while(i < s.length()){
        int idx = s[i] - 'a';
        l = trie[l].succ[idx];
        if(!l) return false;
        i++;
    }
    return trie[l].end;
}

bool query(){ 
    int l = 0;
    for(int i=0; i<s.length(); i++){
        int idx = s[i] - 'a';
        for(int c=0; c<26; c++){
            if(c == idx) continue;
            if(trie[l].succ[c] == 0) continue;
            if(query_intol(i+1, trie[l].succ[c])) return true;
        }
        l = trie[l].succ[idx];
        if(l == 0) return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    TAIL = 1;
           
    cin >> N >> M;

        
    for(int i=0; i<N; i++){            
        cin >> s;
        ins();
    }

    for(int i=0; i<M; i++){
        cin >> s;
        cout << ( query() ? "YES" : "NO") << "\n";
    }

    cout.flush();
}