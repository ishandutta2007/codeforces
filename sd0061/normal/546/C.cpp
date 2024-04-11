#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

queue<int> a , b;

int main() {

    int i , j;
    cin >> j;
    cin >> j;
    while (j --)
        cin >> i , a.push(i);
    cin >> j;
    while (j --)
        cin >> i , b.push(i);
    int K = 0;
    while (K < 36288000) {
        if (a.empty()) {
            printf("%d 2\n" , K);
            return 0;
        }
        if (b.empty()) {
            printf("%d 1\n" , K);
            return 0;
        }
        if (a.front() > b.front()) {
            a.push(b.front());
            b.pop();
            a.push(a.front());
            a.pop();            
        } else {
            b.push(a.front());
            a.pop();
            b.push(b.front());
            b.pop();                    
        }
        ++ K;
    }
    puts("-1");
    return 0;
}