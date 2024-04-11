#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int MAXN = (int)1e5 + 500;

int n,m,qi;
bool q[31][MAXN], res[31][MAXN];
int num[MAXN];
int l[MAXN], r[MAXN];
int in[31][MAXN], out[31][MAXN];
int psum[31][MAXN];

int main(){
    fill(num, num+MAXN, 0);
    for(int i = 0; i < 31; i++) fill(in[i], in[i]+MAXN, 0), fill(out[i], out[i]+MAXN, 0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &l[i], &r[i], &qi);
        for(int j = 0; j < 30; j++){
            q[j][i] = (bool)(qi % 2), qi /= 2;
            if(q[j][i]) in[j][l[i]]++, out[j][r[i]+1]++;
        }
    }
    for(int i = 0; i < 30; i++){
        int now = 0;
        for(int j = 1; j <= n; j++){
            now += in[i][j] - out[i][j];
            res[i][j] = (now > 0);
        }
    }

    for(int i = 0; i < 30; i++) psum[i][0] = 0;
    for(int i = 0; i < 30; i++){
        for(int j = 1; j <= n; j++){
            psum[i][j] = psum[i][j-1] + (int)res[i][j];
        }
    }

    for(int i = 0; i < 30; i++){
        for(int j = 0; j < m; j++){
            if(!q[i][j] && psum[i][r[j]] - psum[i][l[j]-1] == (r[j]-l[j]+1))
                return !printf("NO");
        }
    }
    //cout << psum[2][r[1]+1] << " " << psum[2][l[1]]<< endl;

    for(int i = 1; i <= n; i++){
        for(int j = 29; j >= 0; j--){
            num[i] *= 2;
            if(res[j][i]) num[i]++;
        }
    }
    printf("YES\n");
    for(int i = 1; i <= n; i++){
        printf("%d ", num[i]);
    }

}