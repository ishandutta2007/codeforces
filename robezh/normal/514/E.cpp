#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, D = (int)101;
typedef long long ll;
const ll mod = (int)1e9 + 7;

int n,a,x;
int cnt[105];

typedef struct matrix
{
    ll a[D][D];
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    void set_up()
    {
        for(int i = 0; i <= 98; i++){
            a[i][i+1] = 1;
        }
        for(int j = 0; j <= 99; j++) a[99][j] = a[100][j] = cnt[100 - j];
        a[100][100] = 1;
    }
    void identity(){
        for(int i = 0; i < D; i++){
            for(int j = 0; j < D; j++) a[i][j] = (i == j);
        }
    }
    matrix operator * (const matrix &B)const
    {
        matrix C;
        for(int i = 0; i < D; i++)
            for(int j = 0; j < D; j++)
                for(int k = 0; k < D; k++)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % mod;
        return C;
    }
    matrix operator ^ (const ll &p)const
    {
        matrix A=(*this), res;
        res.identity();
        ll t = p;
        while(t > 0)
        {
            if(t % 2) res = res * A;
            A = A * A;
            t /= 2;
        }
        return res;
    }
}mat;

int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a;
        cnt[a]++;
    }
    mat mtx;
    mtx.set_up();
    mtx = (mtx ^ x);
    cout << (mtx.a[100][99] + mtx.a[100][100]) % mod << endl;
}