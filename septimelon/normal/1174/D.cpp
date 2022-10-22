#include <bits/stdc++.h>

using namespace std;

long long q;
vector<long long> a;
int cou;

void push(long long wha) {
    if (wha != 1)
        push(wha/2);
    cou++;
    if (wha >= q)
        a.push_back(wha * 2);
    else
        a.push_back(wha);
    if (wha != 1)
        push (wha/2);
}

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    long long xo = 1;
    int num = 1;
    cou = 0;
    bool already = false;
    q = 2;
    while (q < x)
        q *= 2;
    while ((q & x) == 0)
        q /= 2;
    for (int i = 0; i < n; i++) {
        if (q == num)
            already = true;
        num *= 2;
    }
    num /= 2;
    //cout << num << endl;
    if (already)
        num /= 2;
    if (num == 0) {
        cout << "0" << endl;
        return 0;
    }
    push(num);
    cout << cou << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    //cout << (q & x) << " " << q << endl;
    /*while (num < n) {
        if (!already && xo == q) {
            xo *= 2;
            num++;
            already = true;
            continue;
        }
        num++;
        a.push_back(xo);
        xo *= 2;
    }*/
    /*for (int i = a.size()-2; i >= 0; i--) {
        a.push_back(a[i]);
    }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }*/
    return 0;
}