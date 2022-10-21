#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int n;
string a[1005][2];
bool sta[1005];
map<string, int> M,N;

int main() {
    scanf("%d", &n);
    fill(sta, sta+n, false);
    string str1,str2;
    getchar();
    for(int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        a[i][0] = str1.substr(0,3);
        a[i][1] = str1.substr(0,2) + str2[0];
        if(!M.count(a[i][0])) M[a[i][0]] = 1;
        else M[a[i][0]] ++;

        for(int i = 0; i < n; i++) {
            if(M[a[i][0]] >= 2) sta[i] = true;
        }
    }
//    for(int i = 0; i < n; i++) {
//        if(sta[i]) cout << a[i][0] << endl;
//    }
    M.clear();
    for(int i = 0; i < n; i++) {
        if(!sta[i]) M[a[i][0]] = M.count(a[i][0]) ? M[a[i][0]] + 1 : 1;
        else N[a[i][1]] = N.count(a[i][1]) ? N[a[i][1]] + 1 : 1;
        if(N[a[i][1]] >= 2) return !printf("NO");
    }
    for(int i = 0; i < n; i++) {
        if(!sta[i]) {
            for(int j = 0; j < n; j++) {
                if(sta[j] && N.count(a[j][1])) {
                    sta[i] = true;
                    N[a[i][1]] = N.count(a[i][1]) ? N[a[i][1]] + 1 : 1;
                    if(N[a[i][1]] >= 2){
                    	return !printf("NO");
					}
                    break;
                }
            }
        }
    }
    printf("YES\n");
    for(int i = 0; i < n; i++){
    	if(!sta[i]) cout << a[i][0] << endl;
    	else cout << a[i][1] << endl; 
	}
}