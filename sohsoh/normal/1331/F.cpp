// this is just a copy pasted code !!!   

#include <bits/stdc++.h>
     
    using namespace std;
     
    char x[100];
    bool ok[100];
    string s[] = {"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};
     
    int main() {
    	scanf("%s", x);
    	int n = strlen(x);
    	ok[0] = 1;
    	for (int i = 0; i < n; i++)
    		if (ok[i]) {
    			for (auto j : s) {
    				if (j.size() == 1 && j[0] == x[i])
    						ok[i + 1] = 1;
    				if (j.size() == 2 && j[0] == x[i] && j[1] == x[i + 1])
    						ok[i + 2] = 1;
    			}
    		}
    	puts(ok[n] ? "YES" : "NO");
    }