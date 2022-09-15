# To change this template, choose Tools | Templates
# and open the template in the editor.
def r(x):
    return x,5

s=raw_input()
c=0
for i in range(len(s)):
    if s[i]>='a':
        c=c+1
if c>=len(s)-c:
    print s.lower()
else:
    print s.upper()