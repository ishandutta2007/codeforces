#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main(){


    int n;
    cin >> n;

    map<string, vector<string> > a;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;

        int m;
        cin >> m;

        for(int j = 0; j < m; j++){
            string s;
            cin >> s;

            a[name].push_back(s);
        }

        vector<string> b = a[name];

        a[name] = vector<string>(0);

        for(int j = 0; j < b.size(); j++){
            bool flag = false;
            for(int l = 0; l < b.size(); l++)if(l != j && b[j].length() < b[l].length()){
                if(b[j] == b[l].substr(b[l].length() - b[j].length(), b[j].length()))flag = true;
                //cout << b[j] << ' ' << b[l] << ' '
                //    << b[l].substr(b[l].length() - b[j].length(), b[j].length()) << endl;
            }


            if(!flag)a[name].push_back(b[j]);
        }

    }

    for(map<string, vector<string> >::iterator i = a.begin(); i != a.end(); i++){
        vector<string> b = i -> second;
        vector<string> c;

        for(int j = 0; j < b.size(); j++){
            bool flag = false;
            for(int l = 0; l < j; l++)
                if(b[l] == b[j])flag = true;
            if(!flag)c.push_back(b[j]);
        }

        i -> second = c;
    }

    cout << a.size() << endl;
    for(map<string, vector<string> >::iterator i = a.begin(); i != a.end(); i++){
        cout << i->first << ' ' << i->second.size() << ' ';

        for(int j = 0; j < i->second.size(); j++)cout << i->second[j] << ' ';

        cout << endl;
    }
}