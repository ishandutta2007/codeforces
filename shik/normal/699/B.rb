n, m = gets.split.map(&:to_i)
map = []
cx = Array.new(n, 0)
cy = Array.new(m, 0)
n.times do |i|
  map[i] = gets
  map[i].each_char.with_index do |c, j|
    next unless c == '*'
    cx[i] += 1
    cy[j] += 1
  end
end
tot = cx.inject(:+)
n.times do |i|
  m.times do |j|
    cnt = cx[i] + cy[j]
    cnt -= 1 if map[i][j] == '*'
    if cnt == tot
      puts 'YES'
      puts [i + 1, j + 1] * ' '
      exit
    end
  end
end

puts 'NO'