#include <bits/stdc++.h>
using namespace std;

int main (){
    long long n, a, sum = 0, m;
    vector<long long> s;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
    	cin >> a;
    	sum += a;
    }
    for(int i = 0; i < n; i++)
    {
    	cin >> a;
    	s.push_back(a);
    }
    sort(s.begin(), s.end());
    m = s[s.size() - 1] + s[s.size() - 2];
    if(m < sum) cout << "NO";
    else cout << "YES";
}