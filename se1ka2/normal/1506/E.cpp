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
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        priority_queue<int, vector<int>, greater<int>> que0;
        int last = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == last){
                cout << que0.top() << " ";
                que0.pop();
            }
            else{
                cout << a[i] << " ";
                for(int j = last + 1; j < a[i]; j++) que0.push(j);
                last = a[i];
            }
        }
        cout << endl;
        priority_queue<int> que1;
        last = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == last){
                cout << que1.top() << " ";
                que1.pop();
            }
            else{
                cout << a[i] << " ";
                for(int j = last + 1; j < a[i]; j++) que1.push(j);
                last = a[i];
            }
        }
        cout << endl;
    }
}