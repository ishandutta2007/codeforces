/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;


const int alph = 26;


vector<char> str;
vector<int> p;
vector<vector<int>> go;


void add(char c){
    str.push_back(c);
    int i = (int)(str.size()) - 1;
    p.push_back(0);
    go.push_back(vector<int>(alph, 0));
    if(i > 0){
        p[i] = p[i - 1];
        if(str[p[i]] != c && p[i] - 1 >= 0){
            p[i] = go[p[i] - 1][c - 'a'];
        }
        if(str[p[i]] == c){
            p[i] += 1;
        }
        for(int t = 0; t < alph; t += 1){
            if(str[p[i]] - 'a' == t){
                go[i][t] = p[i];   
            } else if(p[i] - 1 >= 0){
                go[i][t] = go[p[i] - 1][t];
            }
        }
    }
}


void pop(){
    str.pop_back();
    p.pop_back();
    go.pop_back();
}


int main()
{
    string s;
    cin >> s;
    for(auto t: s){
        add(t);
    }
    int q;
    cin >> q;
    while(q--){
        string a;
        cin >> a;
        for(auto t: a){
            add(t);
            cout << p.back() << " ";
        }
        cout << "\n";
        for(auto t: a){
            pop();
        }
    }
    
    return 0;
}