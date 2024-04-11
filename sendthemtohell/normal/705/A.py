n=int(input())
ans=""
for i in range(n-1):
  if i%2:
    ans+="I love that "
  else:
    ans+="I hate that "
if n%2:
  ans+="I hate it"
else:
  ans+="I love it"
print(ans)