#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define P1 1000000007
#define P2 31

int nxt[1000100],len;
char S[1000100];
bool appear[1000100];

int main(){
	scanf("%s",S+1);
	len=strlen(S+1);
	for(int i=2;i<=len;++i){
		int j=nxt[i-1];
		while(j&&S[j+1]!=S[i]) j=nxt[j];
		nxt[i]=j+(S[j+1]==S[i]);
		}
	for(int i=2;i<len;++i) appear[nxt[i]]=1;
	for(int i=len;i;--i) appear[nxt[i]]|=appear[i];
	int ans=nxt[len];
	while(ans&&!appear[ans]) ans=nxt[ans];
	if(ans==0) printf("Just a legend\n");
	else S[ans+1]=0,printf("%s",S+1);
	scanf("%s",S+1);
	return 0;
}