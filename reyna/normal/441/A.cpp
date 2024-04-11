#include <iostream>
using namespace std;
bool ans[51];
int main(){
    int n,v;
    cin >> n >> v;
    int counter = 0;
    for(int i = 0; i<n;i++){
        int k;
        cin >> k;
        for(int j = 0; j<k;j++){
            int l;
            cin >> l;
            if(v > l){
                ans[i] = true;
            }
    //      cout << ans[i];
        }
    //  cout << endl;
        if(ans[i] == true){
            counter++;
        }
    }
    cout << counter << endl;
    for(int i = 0 ; i < n ; i++){
        if(ans[i] == true){
            cout << i+1 << " ";
        }
    }
}