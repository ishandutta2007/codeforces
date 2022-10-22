#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    priority_queue<int , vector<int> , greater<int> > Q;
    vector< pair<string , int> > V;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        char str[10];
        int x;
        scanf("%s" , str);
        if (*str == 'i') {
            scanf("%d" , &x);
            Q.push(x);
            V.push_back(make_pair("insert" , x));
        }
        if (*str == 'g') {
            scanf("%d" , &x);
            while (!Q.empty() && Q.top() < x) {
                Q.pop();
                V.push_back(make_pair("removeMin" , 0));
            }
            if (Q.empty() || Q.top() != x) {
                Q.push(x);
                V.push_back(make_pair("insert" , x));
            }

            V.push_back(make_pair("getMin" , x));
        }
        if (*str == 'r') {
            if (Q.empty()) {
                Q.push(1);
                V.push_back(make_pair("insert" , 1));
            }
            Q.pop();
            V.push_back(make_pair("removeMin" , 0));
        }
    }
    cout << V.size() << endl;
    for (auto &it : V) {
        cout << it.first;
        if (it.first[0] != 'r') {
            cout << ' ' << it.second << endl;
        } else {
            cout << endl;
        }
    }

}