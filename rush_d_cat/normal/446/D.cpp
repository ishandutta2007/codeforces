#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 502;
const double EPS = 1e-10;
int n,m,k,a[N],mp[N][N],idx[N];
vector<int> g[N];
double mat[N][N],p[N][N],b[N];
struct order {
    int type;
    int x,y; double k;
} O[1000000+10]; int tot=0;

void gauss(){
    // Ax = b
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(mp[i][j]) {
                cnt+=mp[i][j];
            }
        }
        for(int j=0;j<n;j++){
            if(i==j){
                mat[i][j]=1.0;
            } 
            if(mp[i][j] && a[i]==0) {
                mat[j][i]=-1.0*mp[i][j]/cnt;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(abs(mat[i][i]) < EPS) {
            for(int j=i;j<n;j++){
                if(abs(mat[j][i]) > EPS) {
                    O[++tot].type=1, O[tot].x=i, O[tot].y=j;
                    for(int k=0;k<n;k++){
                        swap(mat[i][k], mat[j][k]);
                    }
                    break;
                }
            }
        }

        for(int j=i+1;j<n;j++){
            if(abs(mat[j][i]) > EPS) {
                double r=mat[j][i]/mat[i][i];
                O[++tot].type=2, O[tot].x=i, O[tot].y=j, O[tot].k=-r;
                for(int k=0;k<n;k++){
                    mat[j][k] -= r * mat[i][k];
                }
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(abs(mat[i][i]) > EPS) {
            for(int j=i-1;j>=0;j--){
                O[++tot].type=2, O[tot].x=i, O[tot].y=j, O[tot].k=-mat[j][i]/mat[i][i];
                mat[j][i] = 0;
            }
        }
    }
}
void solve(int u){
    // p[u][?]
    int deg=0; for(int i=0;i<n;i++)if(mp[u][i]) deg+=mp[u][i];
    for(int i=0;i<n;i++){
        b[i]=0;
        for(int j=0;j<n;j++){
            if(mp[i][j] && j==u) b[i]=1.0*mp[i][j]/deg;
        }
    }
    for(int i=1;i<=tot;i++){
        if(O[i].type == 1) {
            swap(b[O[i].x], b[O[i].y]);
        } else {
            b[O[i].y] += b[O[i].x] * O[i].k;
        }
    }
    for(int i=0;i<n;i++) {
        if(idx[i] != -1) {
            p[idx[u]][idx[i]] = b[i] / mat[i][i];
        } 
    }
}
int now=0; 

struct Matrix
{
    double a[110][110];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<now;i++)
            for(int j=0;j<now;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<now;i++)
            for(int j=0;j<now;j++)
                for(int k=0;k<now;k++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j]);
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
};
void Init() {
    for(int i=0;i<now;i++){

        double sum=0;
        for(int j=1;j<now;j++) 
            sum+=p[i][j];

        for(int j=1;j<now;j++) {
            if(sum>EPS)
                p[i][j]/=sum;
        } //printf("\n");
        p[i][0]=0;
    }
    //printf("ok\n");
    Matrix M;
    for(int i=0;i<now;i++)for(int j=0;j<now;j++) M.a[j][i]=p[i][j];
    M=M^(k-1);
    //printf("---------\n");

    printf("%.5f\n", M.a[now-1][0]);
}


int main(){
    memset(idx,-1,sizeof(idx));
    scanf("%d%d%d",&n,&m,&k);
    idx[0]=now++;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if(i>0 && a[i]) idx[i]=now++;
    }
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);--u,--v;
        mp[u][v]++;mp[v][u]++;
    }
    gauss();
    for(int i=0;i<n;i++){
        if(a[i]==1 || i==0) {
            solve(i);
        }
    }
    Init();
    // F[i] = f[i][1] + f[i][2] + .....
    // F[i] = F[j1] / c1 + F[j2] / c2
    // F[i] = (F[j1] + F[j2] + F[j3] + 1) / cnt
}