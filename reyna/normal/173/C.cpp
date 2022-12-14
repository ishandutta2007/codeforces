//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 530;
const int oo = Maxn * Maxn * 1001;
int rec[Maxn][Maxn][2];
int spiral[Maxn][Maxn][2];
int line[Maxn][Maxn][2];
int mat[Maxn][Maxn];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            scanf("%d",&mat[i][j]);
    for(int i = 0; i < n;i++){
        line[i][0][0] = mat[i][0];
    }
    for(int i = 0; i < n;i++)
        for(int j = 1; j < m;j++)
            line[i][j][0] = line[i][j-1][0] + mat[i][j];
    for(int i = 0; i < m;i++)
        line[0][i][1] = mat[0][i];
    for(int i = 1; i < n;i++)
        for(int j = 0; j < m;j++)
            line[i][j][1] = line[i-1][j][1] + mat[i][j];
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++){
            rec[i][j][0] = mat[i][j];
            spiral[i][j][0] = mat[i][j];
        }
    int ans = -oo;
    int cnt = 2;
    for(int size = 1; cnt < max(n,m);size = 1-size,cnt += 2){
        for(int i = 0; i + cnt < n;i++){
            for(int j = 0; j + cnt < m;j++){
                rec[i][j][size] = rec[i+1][j+1][1-size];
                for(int a = 0; a <= cnt; a += cnt)
                    for(int b = 0; b <= cnt; b += cnt)
                        rec[i][j][size]-=mat[i+a][j+b];
                rec[i][j][size] += line[i][j+cnt][0] - line[i][j][0] + mat[i][j];
                rec[i][j][size] += line[i+cnt][j+cnt][0] - line[i+cnt][j][0] + mat[i+cnt][j];
                rec[i][j][size] += line[i+cnt][j][1] - line[i][j][1] + mat[i][j];
                rec[i][j][size] += line[i+cnt][j+cnt][1] - line[i][j+cnt][1] + mat[i][j+cnt];
                spiral[i][j][size] = rec[i][j][size] - spiral[i+1][j+1][1-size] - mat[i+1][j];
        //      cerr << i << " " << j << " " << cnt << " --> val : " << rec[i][j][size] << endl;
                ans = max(ans,spiral[i][j][size]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}