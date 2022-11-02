// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n;
    char s[1000];
    scanf("%d",&n);
    while ( n-- ) {
        scanf("%s",s);
        vector<int> ip;
        int p=0;
        while ( s[p] ) {
            if ( s[p]==':' ) {
                ip.push_back(-1);
                p++;
            } else {
                char buf[10];
                sscanf(s+p,"%[0-9a-f]",buf);
                p+=strlen(buf);
                if ( s[p]==':' ) p++;
                int x;
                sscanf(buf,"%x",&x);
                ip.push_back(x);
            }
        }
        int t=8,c=0;
        FOR(it,ip) if ( *it!=-1 ) t--;
        for ( int i=0; i<SZ(ip); i++ ) {
            int z=0;
            if ( ip[i]!=-1 ) z+=printf("%04x",ip[i]);
            else if ( t>0 ) {
                t--;
                i--;
                z+=printf("0000");
            }
            if ( z ) printf("%c",++c==8?'\n':':');
        }
    }
    return 0;
}