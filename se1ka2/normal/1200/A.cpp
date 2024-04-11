#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans[10] {0};
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            for(int j = 0; j < 10; j++){
                if(ans[j] == 0){
                    ans[j] = 1;
                    break;
                }
            }
        }
        else if(s[i] == 'R'){
            for(int j = 9; j >= 0; j--){
                if(ans[j] == 0){
                    ans[j] = 1;
                    break;
                }
            }
        }
        else ans[s[i] - '0'] = 0;
    }
    for(int i = 0; i < 10; i++) cout << ans[i];
    cout << endl;
}