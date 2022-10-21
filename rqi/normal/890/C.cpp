#include <iostream>

using namespace std;
int count[200000];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        count[x]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(count[i]!=0){
            ans+=count[i]-1;
        }
    }
    cout << ans+1;
}