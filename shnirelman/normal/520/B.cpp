#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);

    vector<int> d(1000000, -1);

    d[n] = 0;
    q.push(n);

    while(true){
        int a = q.front();
        q.pop();

        if(a == m){
            cout << d[a];
            return 0;
        }

        if(a * 2 < d.size() && d[a * 2] == -1){
            d[a * 2] = d[a] + 1;
            q.push(a * 2);
        }
        if(a - 1 > 0 && d[a - 1] == -1){
            d[a - 1] = d[a] + 1;
            q.push(a - 1);
        }


    }
}