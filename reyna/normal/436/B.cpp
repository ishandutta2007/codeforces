//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 2015;
char S[Maxn][Maxn];
int ans[Maxn];
int n,m,k;
bool check(int i,int j){
    if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    return 1;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n;i++)
        scanf("%s",&S[i]);
    for(int j = 0; j < m;j++){
        for(int i = 0; i < n;i++){
            if(check(i,j-i) && S[i][j-i] == 'R')
                ans[j]++;
            if(check(i,j+i) && S[i][j+i] == 'L')
                ans[j]++;
            if(S[i][j] == 'U' && i % 2 == 0)
                ans[j]++;
        }
    }
    for(int i = 0; i < m;i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}