#include <bits/stdc++.h>
using namespace std;

const int N = (int)105;

int n,m,x;
vector<int> num[N];
int a = 0, b = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> x;
            num[i].push_back(x);
        }
    }
    priority_queue<int> pque;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < num[i].size(); j++){
            if(num[i].size() % 2 == 1 && j == num[i].size()/2) pque.push(num[i][j]);
            else if(j < num[i].size() / 2) a += num[i][j];
            else b += num[i][j];
        }
    }
    bool isa = true;
    while(!pque.empty()){
        if(isa) a += pque.top();
        else b += pque.top();
        pque.pop();
        isa = !isa;
    }
    cout << a << " " << b << endl;
}