#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[300005];
    for(int i = 0; i < n; i++) cin >> h[i];
    stack<int> sth, stl;
    sth.push(0);
    stl.push(0);
    int dp[300005];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(h[i] == h[i - 1]){
            sth.pop();
            stl.pop();
            dp[i] = dp[i - 1] + 1;
        }
        if(h[i] > h[i - 1]){
            dp[i] = dp[i - 1] + 1;
            while(!sth.empty()){
                dp[i] = min(dp[i], dp[sth.top()] + 1);
                if(h[sth.top()] > h[i]) break;
                if(h[sth.top()] == h[i]){
                    sth.pop();
                    break;
                }
                sth.pop();
            }
        }
        if(h[i] < h[i - 1]){
            dp[i] = dp[i - 1] + 1;
            while(!stl.empty()){
                dp[i] = min(dp[i], dp[stl.top()] + 1);
                if(h[stl.top()] < h[i]) break;
                if(h[stl.top()] == h[i]){
                    stl.pop();
                    break;
                }
                stl.pop();
            }
        }
        sth.push(i);
        stl.push(i);
    }
    cout << dp[n - 1] << endl;
}