#include <bits/stdc++.h>

using namespace std;
    
int main() {
    int n;
    cin >> n;
    int x;
    int curspeed = 0;
    int curlim;
    int ans = 0;
    stack<int> s;
    s.push(400);
    stack<int> t;
    t.push(9);
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1){
            cin >> curspeed;
            while(s.top() < curspeed){
                s.pop();
                ans++;
            }
                
            
        }
        else if(x == 2){
            while(t.top() < 5){
                ans++;
                t.pop();
            }
        }
        else if(x == 3){
            cin >> curlim;
            s.push(curlim);
            while(s.top() < curspeed){
                s.pop();
                ans++;
            }
        }
        else if(x == 4){
            t.push(9);
        }
        else if(x == 5){
            s.push(400);
        }
        else if(x == 6){
            t.push(0);
        }
    }
    cout << ans;
}