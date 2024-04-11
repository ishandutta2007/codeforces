#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100002], b[100002];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        priority_queue<int, vector<int>, greater<int>> quea;
        priority_queue<int> queb;
        int sa = 0, sb = 0;
        for(int i = 0; i < n; i++){
            quea.push(a[i]);
            sa += a[i];
        }
        for(int i = 0; i < n; i++){
            queb.push(b[i]);
        }
        while((int)quea.size() > n - n / 4){
            sa -= quea.top();
            quea.pop();
        }
        while((int)queb.size() > n / 4){
            sb += queb.top();
            queb.pop();
        }
        for(int k = n + 1; k < n * 100; k++){
            if(sa >= sb){
                cout << k - n - 1 << endl;
                break;
            }
            quea.push(100);
            sa += 100;
            queb.push(0);
            while((int)quea.size() > k - k / 4){
                sa -= quea.top();
                quea.pop();
            }
            while((int)queb.size() > k / 4){
                sb += queb.top();
                queb.pop();
            }
        }
    }
}