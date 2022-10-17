#include <iostream>
using namespace std;

int N, M;
char g[128][128];

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int r = 0;
        for(int j=0; j<M; j++)
            if(g[i][j]){ r = 0; continue; }
            else{
                char b1 = 0, b2 = 0, b3 = 0;
                if(i) b1 = g[i-1][j];
                if(j) b2 = g[i][j-1];
                if(j+1<M) b3 = g[i][j+1];

                char mf = 'A';
                if(b1 == 'A' || b2 == 'A' || b3 == 'A'){
                    mf++;
                    if(b1 == 'B' || b2 == 'B' || b3 == 'B'){
                        mf++;
                        if(b1 == 'C' || b2 == 'C' || b3 == 'C')
                            mf++;
                    }
                }
                
                if(!r || !b2 || b2==b1 || b2==b3 || b2 > mf || i+r>=N){
                    g[i][j] = mf; r=1; continue;
                }
                    
                r++;
                for(int k=i; k<i+r; k++)
                    g[k][j] = b2;
                for(int k=j-r+1; k<=j; k++)
                    g[i+r-1][k] = b2;
            }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << g[i][j];
        cout << "\n";
    }
    cout.flush();
}