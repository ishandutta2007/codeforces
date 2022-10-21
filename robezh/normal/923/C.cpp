#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300500;

int n;
int a[MAXN], p[MAXN];

int trie[9005000][4];
int ts = 1;

void add(int x){
    int k[30];
    for(int i = 29; i >= 0; i--){k[i] = x % 2, x /= 2;}
    int cur = 0;
    for(int i = 0; i < 30; i++){
        if(trie[cur][k[i]+2] > 0){
            trie[cur][k[i]+2] ++;
            cur = trie[cur][k[i]];
        }
        else{
            trie[cur][k[i]+2] ++;
            trie[cur][k[i]] = (ts++);
            cur = ts-1;
        }
    }
}

int get(int x){
    int k[30];
    for(int i = 29; i >= 0; i--){k[i] = x % 2, x /= 2;}
    int cur = 0, res = 0;
    for(int i = 0; i < 30; i++){
        int nxt1 = trie[cur][1];
        int nxt0 = trie[cur][0];
        if((k[i]==1)){
            if(trie[cur][3] > 0){
                trie[cur][3]--;
                cur = nxt1;
                res = res*2;
            }
            else{
                trie[cur][2]--;
                cur = nxt0;
                res = res*2+1;
            }
        }
        else{
            if(trie[cur][2] > 0){
                trie[cur][2]--;
                cur = nxt0;
                res = res*2;
            }
            else{
                trie[cur][3]--;
                cur = nxt1;
                res = res*2+1;
            }
        }
    }
    return res;

}

int main(){
    for(int i = 0; i < 9005000; i++) fill(trie[i], trie[i]+4, 0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]), add(p[i]);
    //cout << trie[0][2] << endl;
    for(int i = 0; i < n; i++) printf("%d ", get(a[i]));
}