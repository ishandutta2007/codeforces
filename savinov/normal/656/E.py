#!/usr/bin/env python


s = "\
n = int(raw_input())\n\
d = []\n\
fo" + "r i in xrange(n):\n\
    d.append(map(int, raw_input().split()))\n\
\n\
fo" + "r k in xrange(n):\n\
    fo" + "r i in xrange(n):\n\
        fo" + "r j in xrange(n):\n\
            d[i][j] = min(d[i][j], d[i][k] + d[k][j])\n\
\n\
ans = 0\n\
\n\
fo" + "r i in xrange(n):\n\
    fo" + "r j in xrange(n):\n\
        ans = max(ans, d[i][j])\n\
\n\
print ans\n"

exec s