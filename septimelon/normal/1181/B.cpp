#include <bits/stdc++.h>

using namespace std;

string sum(string ss1, string ss2) {
    int add = 0;
    string ans = "";
    int ind1 = ss1.size()-1;
    int ind2 = ss2.size()-1;
    char nex;
    while (ind1 >= 0 && ind2 >= 0) {
        nex = ss1[ind1]+ss2[ind2]-'0'+add;
        ind1--;
        ind2--;
        if (nex > '9') {
            nex -= 10;
            add = 1;
        }
        else add = 0;
        ans += nex;
    }
    while (ind1 >= 0) {
        nex = ss1[ind1]+add;
        ind1--;
        if (nex > '9') {
            nex -= 10;
            add = 1;
        }
        else add = 0;
        ans += nex;
    }
    while (ind2 >= 0) {
        nex = ss2[ind2]+add;
        ind2--;
        if (nex > '9') {
            nex -= 10;
            add = 1;
        }
        else add = 0;
        ans += nex;
    }
    if (add != 0)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

string sma(string s1, string s2) {
    if (s1 == "")
        return s2;
    if (s2 == "")
        return s1;
    if (s1.size() < s2.size())
        return s1;
    if (s1.size() > s2.size())
        return s2;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i])
            return s1;
        if (s1[i] > s2[i])
            return s2;
    }
    return s1;
}

int main()
{
    string n, s1, s2, sum1, sum2, sum3;
    int l;
    cin >> l >> n;
    int ind = l/2+1;
    s1 = "";
    s2 = "";
    sum1 = "";
    sum2 = "";
    sum3 = "";
    while (n[ind] == '0' && ind < l)
        ind++;
    if (ind != l) {
        for (int i = 0; i < ind; i++)
            s1 += n[i];
        for (int i = ind; i < l; i++)
            s2 += n[i];
        //cout << s1 << " " << s2 << endl;
        sum1 = sum(s1, s2);
    }
    ind = l/2;
    while (n[ind] == '0' && ind > 0)
        ind--;
    if (ind > 0) {
        s1 = "";
        s2 = "";
        for (int i = 0; i < ind; i++)
            s1 += n[i];
        for (int i = ind; i < l; i++)
            s2 += n[i];
        //cout << s1 << " " << s2 << endl;
        sum2 = sum(s1, s2);
    }
    ind = l/2-1;
    while (n[ind] == '0' && ind > 0)
        ind--;
    if (ind > 0) {
        s1 = "";
        s2 = "";
        for (int i = 0; i < ind; i++)
            s1 += n[i];
        for (int i = ind; i < l; i++)
            s2 += n[i];
        //cout << s1 << " " << s2 << endl;
        sum3 = sum(s1, s2);
    }
    //cout << sum1 << endl << sum2 << endl << sum3 << endl;
    cout << sma(sma(sum1, sum2), sum3) << endl;
    /*if (sum1 == "") {
        cout << sum2 << endl;
        return 0;
    }
    if (sum2 == "") {
        cout << sum1 << endl;
        return 0;
    }
    if (sum1.size() < sum2.size()) {
        cout << sum1 << endl;
        return 0;
    }
    if (sum1.size() > sum2.size()) {
        cout << sum2 << endl;
        return 0;
    }
    for (int i = 0; i < sum1.size(); i++) {
        if (sum1[i] < sum2[i]) {
            cout << sum1 << endl;
            return 0;
        }
        if (sum1[i] > sum2[i]) {
            cout << sum2 << endl;
            return 0;
        }
    }
    cout << sum1 << endl;*/
    return 0;
}