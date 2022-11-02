import sys

def fit(a, b):
    return a[0] == b[0] or a[1] == b[1]

def rec(tok):
    if len(tok) == 1: return True

    last = tok[-3:]
    item = (tuple(last), len(tok))
    if item in mem: return mem[item]

    res = False
    if fit(tok[-1], tok[-2]):
        ntok = tok[:-1]
        ntok[-1] = tok[-1]
        if rec(ntok): res = True

    if not res and len(tok) > 3 and fit(tok[-1], tok[-4]):
        ntok = tok[:-1]
        ntok[-3] = tok[-1]
        if rec(ntok): res = True

    mem[item] = res
    return res


tok = []
for line in sys.stdin:
    tok = line.strip().split()

mem = {}
if rec(tok): print "YES"
else: print "NO"