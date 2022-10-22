#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> b;
    int j = 0;
    while(j < n && a[j] <= m){
        b.push_back(a[j]);

        j++;
    }

    int ind = b.size();
    int cnt = 0;
    for(int i = 1; i <= a[n-1]; i++){

        int s = b.size();
        if(ind < n && a[ind] < i + m){b.push_back(a[ind]); ind++;}

        if(s > 0 && b[0] < i) b.erase(b.begin(), b.begin()+1);
        s = b.size();
        //cout << s;
        if(s >= k){
            b.erase(b.end() - s + k - 1, b.end());
            cnt += s - k + 1;

        }


    }

    cout << cnt;
}