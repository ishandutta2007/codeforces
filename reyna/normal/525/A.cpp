//In the name of God
#include <iostream>
using namespace std;
int arr[26];
int main(){
    int n;
    cin >> n;
    string S;
    cin >> S;
    int ans = 0;
    for(int i = 0; i < 2 * n - 2;i++){
        if(i % 2 == 0){
            arr[S[i] - 'a']++;
        }
        if(i % 2){
            if(arr[S[i] - 'A'])
                arr[S[i]-'A']--;
            else
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}