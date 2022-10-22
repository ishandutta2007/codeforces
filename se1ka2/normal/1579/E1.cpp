#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[200005];
        for(int i = 0; i < n; i++) cin >> p[i];
        deque<int> dq;
        dq.push_front(p[0]);
        for(int i = 1; i < n; i++){
            if(p[i] < dq.front()) dq.push_front(p[i]);
            else dq.push_back(p[i]);
        }
        for(int i = 0; i < n; i++){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
}