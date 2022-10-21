#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n;
int a[N];
ll sum = 0;

void First() {
    cout << "sjfnb" << endl;
    exit(0);
}

void Second() {
    cout << "cslnb" << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int cnt = 0, rev = 0;
    vector<int> same;
    if(n > 1 && a[1] == 0) Second();

    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) same.push_back(a[i]);
    }
    if(same.size() >= 2) Second();
    if(same.size() == 1) {
        rev = 1;
        for(int i = 0; i < n; i++) {
            if(same[0] == a[i]) {
                a[i]--;
                if(i > 0 && a[i-1] == a[i]) Second();
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) sum += a[i] - i;
    if((sum % 2 == 1) ^ rev) First();
    else Second();
}