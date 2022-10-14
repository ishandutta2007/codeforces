n, k = map(int, input().split())
s = input()
hah = ''
balance = 0
cnt9 = 0
cnt0 = 0
for i in s:
    if i == '(':
        if cnt9 < k//2:
            hah += '('
            balance += 1
            cnt9 += 1
    else:
        if balance:
            if cnt0 < k//2:
                hah += ')'
                balance -= 1
                cnt0 += 1
print(hah)