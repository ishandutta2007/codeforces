#include <unordered_set>
#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

bool operator!=(vector<string> &a, vector<pair<string, string> > &b){
    for(int i = 0; i<a.size(); i++)
        if(a[i]!=b[i].first)
            return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("digits.in");
    //ofstream cout("digits.out");
    string s;
    int n = 0;
    vector<string> a;
    vector<pair<string, string> > b;
    while(cin >> s){
        if(s[0]=='\\'){
            if(s[1]=='c'){
                string ans = "";
                for(int i = 6; s[i]!='}'; i++)
                    ans.push_back(s[i]);
                a.push_back(ans);
            }
            else{
                if(s[1]=='b'){
                    if(s[2]=='e'){
                        string ans = "";
                        for(int i = 24; s[i]!='}'; i++)
                            ans.push_back(s[i]);
                        stringstream ss;
                        ss << ans;
                        ss >> n;
                    }
                    else{
                        string ans = "";
                        for(int i = 9; s[i]!='}'; i++)
                            ans.push_back(s[i]);
                        b.push_back({ans, ""});
                        b[b.size()-1].second = s;
                        continue;
                    }
                }
                else
                    break;
            }
        }
        if(b.size()){
            stringstream ss;
            ss << b[b.size()-1].second << ' ' << s;
            getline(ss, b[b.size()-1].second);
        }
    }
    if(b.size()>n||a!=b){
        cout << "Incorrect" << '\n';
        cout << "\\begin{thebibliography}{99}" << '\n';
        for(int i = 0; i<a.size(); i++){
            for(int j = 0; j<b.size(); j++){
                if(b[j].first==a[i]){
                    cout << b[j].second << '\n';
                    break;
                }
            }
        }
        cout << "\\end{thebibliography}" << '\n';
    }
    else
        cout << "Correct";

    return 0;
}
///aaaaa.aaaab..ab
/*
-1 1 -1
0 0 2 4
*/