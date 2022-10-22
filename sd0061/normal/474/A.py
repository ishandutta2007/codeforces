D = ['qwertyuiop' , 'asdfghjkl;' , 'zxcvbnm,./']

L = {}
R = {}

for S in D:
    p = '!'
    for c in S:
        L[p] = c
        R[c] = p
        p = c

d = raw_input()
S = raw_input()
T = ''

if d == 'L':
    for c in S:
        T += L[c]
else:
    for c in S:
        T += R[c]
print T