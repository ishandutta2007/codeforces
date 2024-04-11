s = input()
t = input()
fl = 1
if len(s) != len(t):
    print('no')
else:
    sk = set()
    tk = set()
    for u in range(len(s)):
        sk = s[u]
        tk = t[u]
        if (len({'a', 'e', 'i', 'o', 'u'}.intersection(sk)) == 1 and len(
                {'a', 'e', 'i', 'o', 'u'}.intersection(tk)) == 1) or (
                len({'a', 'e', 'i', 'o', 'u'}.intersection(sk)) == 0 and len(
                {'a', 'e', 'i', 'o', 'u'}.intersection(tk)) == 0):
            continue
        else:
            fl = 0
    if fl:
        print('yes')
    else:
        print('no')