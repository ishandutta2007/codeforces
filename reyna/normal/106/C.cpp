#include <iostream>
using namespace std;
int arr[1001][11];
int c[11];
int d[11];
int a[11];
int b[11];
int main(){
    int n,m;
    cin >> n >> m >> c[0] >> d[0];
    m++;
    for(int i = 1; i < m;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i = 0; i <= n;i++){
        for(int j = 0; j < m;j++){
            arr[i][j] = -1;
        }
    }
    for(int i = 0; i <= n;i++){
        if(i % c[0] == 0){
            arr[i][0] = (i/c[0])*d[0];
        }
    }
    for(int i = 1; i < m;i++){
        for(int j = 0; j <= n;j++){
            for(int k = 0; k <= a[i]/b[i]; k++){
                if(j >= k*c[i] && arr[j-k*c[i]][i-1] != -1){
                    arr[j][i] = max(arr[j][i],arr[j-k*c[i]][i-1]+k*d[i]);
                }
            }
        //  cout << arr[j][i] << " ";
        }
        //cout << endl;
    }
    int answer = 0;
    for(int i = 0; i <= n;i++){
        answer = max(answer,arr[i][m-1]);
    }
    cout << answer << endl;
    return 0;
}