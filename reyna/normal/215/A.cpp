#include <iostream>
using namespace std;
int N[50];
int M[50];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> N[i];
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> M[i];
    }
    int max = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(M[i]%N[j]==0){
                if(M[i]/N[j] > max){
                    max = M[i]/N[j];
                }
            }
        }
    }
    int counter = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(M[i]%N[j]==0){
                if(M[i]/N[j] == max){
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;
    return 0;
}