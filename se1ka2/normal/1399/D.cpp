#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        s += '2';
        int l0 = 0, l1 = 0;
        priority_queue<int, vector<int>, greater<int>> que0, que1;
        int ans[200005];
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(que1.size()){
                    ans[i] = que1.top();
                    que1.pop();
                }
                else{
                    l0++;
                    ans[i] = l0;
                }
                l0 = max(l0, ans[i]);
                que0.push(ans[i]);
            }
            else{
                if(que0.size()){
                    ans[i] = que0.top();
                    que0.pop();
                }
                else{
                    l1++;
                    ans[i] = l1;
                }
                l1 = max(l1, ans[i]);
                que1.push(ans[i]);
            }
        }
        cout << max(l0, l1) << endl;
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}