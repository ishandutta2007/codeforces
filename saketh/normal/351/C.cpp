#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f7f7f7f7f7f7f7f;

struct mat{
    int N;
    vector<vector<ll> > dat;

    mat(int _N, ll diag = 0){
        N = _N;
        dat.resize(N);
        for(int i=0; i<N; i++){
            dat[i].resize(N, INF);
            dat[i][i] = diag;
        }
    }

    mat operator *(mat &b){
        mat r(N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++){
                r[i][j] = INF;
                for(int k=0; k<N; k++)
                    r[i][j] = min(r[i][j], dat[i][k] + b[k][j]);
            }
        return r;
    }
    
    mat pow(ll E){
        if(!E) return mat(N, 0);
        mat r = (*this * *this).pow(E/2);
        return E&1 ? r * *this : r;
    }
    
    vector<ll>& operator[](int i){
        return dat[i];
    }

    friend ostream& operator<<(ostream &os, mat &m){
        os << "{";
        for(int i=0; i<m.N; i++){
            if(i) os << "},\n ";
            os << "{";
            for(int j=0; j<m.N; j++){
                if(j) os << ", ";
                os << setw(10) << m[i][j] << setw(0);
            }
        }
        return os << "}}";
    }
};

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

int N, M;
int A[25], B[25];

int main(){
    setup();
    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> A[i];

    for(int i=0; i<N; i++)
        cin >> B[i];

    mat m(2*N);
    for(int i=0; i<2*N; i++)
        for(int j=0; j<2*N; j++)
            m[i][j] = INF;

    for(int b=0; b<(1<<N); b++){
        int st = 0, lo = 0, tc = 0;
        for(int j=0; j<N; j++){
            if((b>>j)&1){
                st++;
                tc += A[j];
            }
            else{
                st--;
                tc += B[j];
            }
            lo = min(lo, st);
        }

        for(int i=0; i<2*N; i++){
            if(i+st < 0 || i+st >= 2*N) continue;
            if(i < -lo) continue;
            m[i][i+st] = min(m[i][i+st], ll(tc));
        } 
    }

    mat m2 = m.pow(M);
    cout << m2[0][0] << endl;
}