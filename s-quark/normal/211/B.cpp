#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef double du;
typedef long long ll;

int cnt[27][27];
vector<int> q, prev;
int pre[10004], f[10004];
short num[1<<26];
int num1[10004];
char s[1000004];
char t[30];

int main(){
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n, m;
    int i, j, k;
    scanf("%s", s);
    scanf("%d", &m);
    memset(num, -1, sizeof num);
    for(i = 0; i < m; i++){
        scanf("%s", t);
        j = 0;
        for(k = 0; t[k]; k++)
            j |= 1<<(t[k]-'a');
        num1[i] = j;
        if(num[j] == -1)
            num[j] = i;
    }
    q.pb(26);
    for(i = 0; s[i]; i++){
        k = s[i]-'a';
        for(j = 0; j < q.size(); j++)
            if(q[j] == k)
                break;
        if(j < q.size()){
            while(j+1 < q.size()){
                q[j] = q[j+1];
                j++;
            }
            q[j] = k;
        }
        else
            q.pb(k);
        j = 0;
        for(k = q.size()-1; k > 0; k--){
            j |= 1<<q[k];
            if(num[j] != -1){
                if(!pre[num[j]])
                    f[num[j]]++;
            }
        }
        for(j = 0; j < prev.size(); j++)
            pre[prev[j]] = 0;
        prev.clear();
        j = 0;
        for(k = q.size()-1; k > 0; k--){
            j |= 1<<q[k];
            if(num[j] != -1){
                pre[num[j]]=1;
                prev.pb(num[j]);
            }
        }
    }
    for(i = 0; i < m; i++)
        cout<<f[num[num1[i]]]<<endl;
    return 0;
}