n = int(raw_input())
ss = raw_input()
fact = [0 for i in xrange(0,20)]
fact[0] = 1
for i in range(1, 11):
    fact[i] = fact[i - 1] * i
s = ""
ret = 1
for i in ss:
    ret *= fact[int(i)]
while ret % fact[7] == 0:
    s += '7'
    ret /= fact[7]
while ret % fact[5] == 0:
    s += '5'
    ret /= fact[5]
while ret % fact[3] == 0:
    s += '3'
    ret /= fact[3]
while ret % fact[2] == 0:
    s += '2'
    ret /= fact[2]
print(s)