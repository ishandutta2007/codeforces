#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


vector <int> z_func(string s) {
    int l = 0, r = 0;
    int n = s.size();
    vector <int> data(n, 0);
    data[0] = -1;
    for (int i = 1; i < n; i++) {
        int k = i;
        if (i <= r) {
            k += min(r - i + 1, data[i - l]);
        }
        while (k < n && s[k] == s[k - i]) {
            k++;
        }
        data[i] = k - i;
        if (k > r) {
            r = k - 1;
            l = i;
        }
    }
    return data;

}




int main() {
    string str;
    cin >> str;
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() == 1) continue;
        string s1 = s + '#' + str;
        vector <int> a1 = z_func(s1);
        //cout << s1 << endl;
       // for (int i = s.size() + 1; i < a1.size(); i++) {
         //   cout << a1[i] << " ";
        //}
       // cout << endl;
        string s2 = str + '#' + s;
        reverse(s2.begin(), s2.end());
        vector <int> a2 = z_func(s2);
        int it = s2.size() - 1;
        vector <int> maxn(2 * s2.size() + 1, 0);
        for (int i = s.size() + 1; i < s2.size(); i++) {
            maxn[it - a2[i] + 1] = max(maxn[it - a2[i] + 1], a2[i]);
            //cout << maxn[it] << " ";
            it--;
        }
        it = s2.size() + 1;
        for (int i = s.size() + 1; i < s2.size(); i++) {
            maxn[it] = max(maxn[it], maxn[it + 1]);
            //cout << maxn[it] << " ";
            it--;
        }
      //  cout << endl;
        for (int i = s.size() + 1; i < s1.size() - 1; i++) {
            //cout << a1[i] + maxn[i + a1[i] + 1] << " ";
            int z = i + a1[i];
            if (a1[i] + maxn[z] >= s.size()) {
                sum++;
                break;
            }
        }
        //cout << endl;
    }
    cout << sum << endl;
}
/*
BBABAABAABBBBAB
1
BBABAABAABBA

*/