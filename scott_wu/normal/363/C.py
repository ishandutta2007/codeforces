s = raw_input()

res = ""
for i in s:
    bad = False
    if len (res) >= 2:
        if i == res[-1] and i == res[-2]:
            bad = True
    if len (res) >= 3:
        if i == res[-1] and res[-2] == res[-3]:
            bad = True
    
    if not bad:
        res += i

print res