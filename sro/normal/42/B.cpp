//Go to http://threebody.com/ to learn more about THREEBODY.
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define SZ(s) ((int)(s).size())
#define INT long long
#define Mod 1000000007
#define Inf 0x3f3f3f3f
#define SHENBEN "shurongwang"
using namespace std;
//Coded by charlieyan, all rights reserved.
/*                                               
  mmmm                       mmmm     mmm   mmmm 
 m"  "m  m mm  mmmmm         #   "m     #  m"  "m
 #    #  #"  "    m"         #    #     #  #    #
 #    #  #      m"           #    #     #  #    #
  #mm#   #     #mmmm         #mmm"  "mmm"   #mm#"
                                               # 
*/

bool btn[15][15];
bool hv[15][15];
char tmp[5];

int main(){
	scanf("%s",tmp);
	int x1=tmp[0]-'a'+1,y1=tmp[1]-'0';
	//hv[x1][y1]=1;
	scanf("%s",tmp);
	int x2=tmp[0]-'a'+1,y2=tmp[1]-'0';
	//hv[x2][y2]=1;
	scanf("%s",tmp);
	int x3=tmp[0]-'a'+1,y3=tmp[1]-'0';
	hv[x3][y3]=1;
	scanf("%s",tmp);
	int x4=tmp[0]-'a'+1,y4=tmp[1]-'0';
	for(int i=x1-1;i>=1&&!hv[i][y1];i--){
		btn[i][y1]=1;
	}
	for(int i=x1+1;i<=8&&!hv[i][y1];i++){
		btn[i][y1]=1;
	}
	for(int i=y1-1;i>=1&&!hv[x1][i];i--){
		btn[x1][i]=1;
	}
	for(int i=y1+1;i<=8&&!hv[x1][i];i++){
		btn[x1][i]=1;
	}
	for(int i=x2-1;i>=1&&!hv[i][y2];i--){
		btn[i][y2]=1;
	}
	for(int i=x2+1;i<=8&&!hv[i][y2];i++){
		btn[i][y2]=1;
	}
	for(int i=y2-1;i>=1&&!hv[x2][i];i--){
		btn[x2][i]=1;
	}
	for(int i=y2+1;i<=8&&!hv[x2][i];i++){
		btn[x2][i]=1;
	}
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(x3+i<=8&&x3+i>=1&&y3+j<=8&&y3+j>=1){
				btn[x3+i][y3+j]=1;
			}
		}
	}
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(x4+i<=8&&x4+i>=1&&y4+j<=8&&y4+j>=1){
				if(!btn[x4+i][y4+j]){
					cerr<<i<<' '<<j<<endl;
					puts("OTHER");
					return 0;
				}
			}
		}
	}
	puts("CHECKMATE");
	return 0;
}