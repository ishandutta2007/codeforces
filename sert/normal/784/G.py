s = str(eval(input()));
ans = '';
for i in range(len(s)):
    ans += '>'
    for j in range(int(s[i])):
        ans += '+'
    ans += '++++++++++++++++++++++++++++++++++++++++++++++++.'
print(ans)