#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;

int main()
{
    string s;
    cin >> s;
    vector <int> a;
    for(int i=0, j=s.size()-1; i<j; ) {
        if(s[i]==')') i++;
        else if(s[j]=='(') j--;
        else {
            a.push_back(i+1);
            a.push_back(j+1);
            i++;
            j--;
        }
    }

    if(a.size()==0) {
        puts("0");
        return 0;
    }

    printf("1\n");
    cout << a.size() << endl;
    sort(a.begin(), a.end());
    for(int v : a) cout << v << " ";
}