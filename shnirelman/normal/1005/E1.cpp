#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int ind = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == m)ind = i;
    }

    vector<int> l(ind + 1), r(n - ind);
    l[ind] = 0;
    for(int i = ind - 1; i >= 0; i--)
        if(a[i] < m)l[i] = l[i + 1] - 1;
        else l[i] = l[i + 1] + 1;

    for(int i = 1; i < n - ind; i++)
        if(a[i + ind] < m)r[i] = r[i - 1] - 1;
        else r[i] = r[i - 1] + 1;



    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());

    long long ans = 0;

    /*for(int i = 0; i < l.size(); i++)cout << l[i] << ' ';
    cout << endl;
    for(int i = 0; i < r.size(); i++)cout << r[i] << ' ';
    cout << endl;*/

    /*for(int i = 0; i <= ind; i++){
        int l1 = 0, r1 = r.size();
        while(r1 - l1 > 1){
            int k = (r1 + l1) / 2;
            if(r[k] >= -l[i])r1 = k;
            else l1 = k;
        }
        //cout << i << ' ' << l1 << ' ' << r1 << endl;
        for(int j = r1; j < r.size() && r[j] + l[i] <= 1; j++)ans++;
        if(l[i] + r[l1] >= 0 && l[i] + r[l1] <= 1)ans++;
    }*/

    int k = 0;
    for(int i = 0; i < l.size(); i++){

        long long ansi = 0;
        while(k < r.size() && r[k] + l[i] > 1)k++;
        int k1 = k;
        while(k1 < r.size() && r[k1] + l[i] >= 0){
            k1++;
            ansi++;
        }
        //cout << i << ' ' << ansi << ' ';
        int li = l[i];
        int cnt = 0;
        while(i < l.size() && l[i] == li){
            i++;
            cnt++;
        }
        i--;
        ans += cnt * ansi;
        //cout << i << ' ' << k << endl;
    }

    cout << ans;
}