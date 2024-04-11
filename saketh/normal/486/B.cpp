#include <iostream>
using namespace std;

int N, M, v[105][105];
int a[105][105], b[105][105];
int rs[105], cs[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin >> v[i][j];
            rs[i] += v[i][j];
            cs[j] += v[i][j];
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            a[i][j] = (rs[i]==M) && (cs[j]==N);
            for(int k=0; k<N; k++)
                b[k][j] |= a[i][j];
            for(int k=0; k<M; k++)
                b[i][k] |= a[i][j];
        }
    
    bool good = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            good &= b[i][j] == v[i][j];

    if(!good){ cout << "NO" << endl; return 0; }
    
    cout << "YES\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    cout.flush();
    return 0;
}