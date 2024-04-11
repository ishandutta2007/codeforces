#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , K;
char str[N];

string host[N];
map<string , int> Hash;
map<string , int> Text;
vector<int> path[N];
int id[N];
int cmp(int x , int y) {
    return path[x] < path[y];
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        char *s = str + 7;
        string H , P;        
        for (int j = 0; s[j] ; ++ j) {
            if (s[j] == '/') {
                s[j] = 0;
                H = s;
                s[j] = '/';
                P = s + j + 1;
                break;
            }
        }
        if (H.empty()) {
            H = s;
            P = "A";
        }
        if (!Hash.count(H)) {
            Hash[H] = m;
            host[m ++] = H;
        }
        if (!Text.count(P)) {
            Text[P] = K ++;
        }
        path[Hash[H]].push_back(Text[P]);
    }
    
    for (int i = 0 ; i < m ; ++ i) {
        sort(path[i].begin() , path[i].end());
        path[i].resize(unique(path[i].begin() , path[i].end()) - path[i].begin());                
        id[i] = i;
    }
    sort(id , id + m , cmp);
    vector< pair<int , int> > res;
    for (int i = 0 ; i < m ; ++ i) {
        int j = i;
        while (j < m && path[id[i]] == path[id[j]])
            ++ j;
        if (j - i > 1) {
            res.push_back(make_pair(i , j - 1));
        }
        i = j - 1;
    }
    printf("%d\n" , (int)res.size());
    for (int i = 0 ; i < (int)res.size() ; ++ i) {
        int l = res[i].first , r = res[i].second;
        for (int j = l ; j <= r ; ++ j)
            printf("http://%s%c" , host[id[j]].c_str() , " \n"[j == r]);
    }
    return 0;
}