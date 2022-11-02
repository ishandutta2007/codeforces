n = gets.to_i
d = gets
x = gets.split.map(&:to_i)

ans = nil
last = nil
n.times do |i|
  if d[i] == 'L'
    ans = x[i] - last if last && (ans.nil? || x[i] - last < ans)
  else
    last = x[i]
  end
end

puts ans ? ans / 2 : -1