// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<string> path;
int main()
{
	int n;
	char cmd[20],dir[222],buf[222];
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s",cmd);
		if ( cmd[0]=='p' ) {
			FOR(it,path) printf("/%s",it->c_str());
			puts("/");
		} else {
			scanf("%s",dir);
			if ( dir[0]=='/' ) path.clear();
			for ( char *p=strtok(dir,"/"); p; p=strtok(NULL,"/") ) {
				sscanf(p,"%s",buf);
				if ( strcmp(buf,"..")==0 ) path.pop_back();
				else if ( strlen(buf)>0 ) path.push_back(buf);
			}
		}
	}
	return 0;
}