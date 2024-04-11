#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> a;
    for(int i = 0; i < n; i++){
        int l = -1;
        for(int j = i; j < n; j++)
            if(s[j] == t[i]){
                l = j;
                j = n;
            }

        if(l == -1){
            cout << -1;
            return 0;
        }

        if(l != i){
            /*string s1;
            for(int j = 0; j < i; j++)s1[j] = s[j];
            s1[i] = t[i];
            for(int j = i + 1; j < n; j++)s1[j] = s[j - 1];
            cout << s << ' ' << s1 << endl;
            s = s1;*/
            s.erase(s.begin() + l, s.begin() + l + 1);

            s += ' ';

            for(int j = s.length() - 1; j > i; j--)s[j] = s[j - 1];
            s[i] = t[i];

        }



        for(; l > i; l--)a.push_back(l);
    }

    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++)cout << a[i] << ' ';

}