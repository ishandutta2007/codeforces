chessWeights = {
  'Q': 9,
  'R': 5,
  'B': 3,
  'N': 3,
  'P': 1,
  }

def getWeight(ch):
  if ch in chessWeights:
    return chessWeights[ch]
  elif ch.islower():
    return -getWeight(ch.upper())
  else:
    return 0

board = [raw_input() for _ in range(8)]
count = 0
for row in board:
  for ch in row:
    count += getWeight(ch)

if count > 0:
  ans = 'White'
elif count < 0:
  ans = 'Black'
else:
  ans = 'Draw'

print ans