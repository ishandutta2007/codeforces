#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

//https://kopricky.github.io/code/DataStructure_Advanced/sparse_table_2D.html

template<typename T> class SparseTable_2D {
private:
    const int R, C;
    vector<int> LogTable;
    T**** Table;
public:
    SparseTable_2D(const vector<vector<T> >& v) : R((int)v.size()), C((int)v[0].size()), LogTable(max(R, C) + 1){
        for(int i = 2; i <= max(R, C); ++i){
            LogTable[i] = LogTable[i >> 1] + 1;
        }
        Table = new T***[LogTable[R] + 1];
        for(int k = 0; k <= LogTable[R] ; ++k){
            Table[k] = new T**[LogTable[C] + 1];
            for(int l = 0; l <= LogTable[C]; ++l){
                Table[k][l] = new T*[R];
                for(int i = 0; i < R; ++i){
                    Table[k][l][i] = new T[C];
                }
            }
        }
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                Table[0][0][i][j] = v[i][j];
            }
        }
        for(int k = 1; (1 << k) <= R; ++k){
            for(int i = 0; i + (1 << k) <= R; ++i){
                for(int j = 0; j < C; ++j){
                    Table[k][0][i][j] = max(Table[k - 1][0][i][j], Table[k - 1][0][i + (1 << (k - 1))][j]);
                }
            }
        }
        for(int k = 0; (1 << k) <= R; ++k){
            for(int l = 1; (1 << l) <= C; ++l){
                for(int i = 0; i + (1 << k) <= R; ++i){
                    for(int j = 0; j + (1 << l) <= C; ++j){
                        Table[k][l][i][j] = max(Table[k][l - 1][i][j], Table[k][l - 1][i][j + (1 << (l - 1))]);
                    }
                }
            }
        }
    }
    ~SparseTable_2D(){
        for(int i = 0; i <= LogTable[R]; ++i){
            for(int j = 0; j <= LogTable[C]; ++j){
                for(int k = 0; k < R; ++k){
                    delete[] Table[i][j][k];
                }
                delete[] Table[i][j];
            }
            delete[] Table[i];
        }
        delete[] Table;
    }
    T query(const int lx, const int ly, const int rx, const int ry){
        const int kx = LogTable[rx - lx];
        const int ky = LogTable[ry - ly];
        return max({Table[kx][ky][lx][ly], Table[kx][ky][rx - (1 << kx)][ly], Table[kx][ky][lx][ry - (1 << ky)], Table[kx][ky][rx - (1 << kx)][ry - (1 << ky)]});
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<vector<int>> S(H,vector<int>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>S[i][j];
    
    for(int i=H-1;i>=0;i--){
        for(int j=W-1;j>=0;j--){
            if(i<H-1&&j<W-1&&S[i][j]){
                S[i][j]=min({S[i][j+1],S[i+1][j],S[i+1][j+1]})+1;
            }
        }
    }
    
    SparseTable_2D<int> baka(S);
    
    int Q;cin>>Q;
    while(Q--){
        int u,d,l,r;cin>>u>>l>>d>>r;
        u--;l--;
        int left=0,right=min(d-u,r-l)+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int x=baka.query(u,l,d-(mid-1),r-(mid-1));
            if(x>=mid) left=mid;
            else right=mid;
        }
        cout<<left<<"\n";
    }
}