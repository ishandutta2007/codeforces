//In the name of God
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string S;
    cin >> S;
    int num = 0;
    for(int i = 0; i < n;i++){
        if(S[i] == 'H')
            num++;
    }
    int ans = n;
    for(int i = 0; i < n;i++){
        int now = 0;
        for(int j = 0; j < num;j++){
            if(S[(i + j)%n] == 'T')
                now++;
        }
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}